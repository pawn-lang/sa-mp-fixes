<?xml version="1.0" ?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
<!-- Version: $Id: pawndoc.xsl 3612 2006-07-22 09:59:46Z thiadmer $ -->

<xsl:template match="/">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<title><xsl:value-of select="doc/assembly/name" /></title>
<style type="text/css">
	body { font-family: "verdana", sans-serif; font-size: x-small; }
	code { font-size: small; }
	dl { margin-left: 4em; display: compact; }
	dt { font-weight: bold; }
	a:link { color: #4e4887; }
	a:visited { color: #8080c8; }
	a:active { color: #f16043; }
	a:hover { color: #f16043; }
	p { margin-bottom: 0.5em; margin-top: 0.5em; margin-left: 4em; }
	p.noindent { margin-left: 0em; }
	p.syntax { font-weight: bold; }
	hr.para { height: 0; border: 0; color: transparent; background-color: transparent; margin-top: 0.5em; margin-bottom: 0; }
	xmp { background-color: #ddeeff; font-size: x-small; margin: 1em; }
	pre { background-color: #ddeeff; font-size: x-small; margin: 1em; }
	table { border-bottom: medium none; border-left: medium none; border-right: medium none; border-top: medium none; }
	table.param { background-color: #ddeeff; }
	table.transition { background-color: #ddeeff; }
	td { background-color: #ddeeff; border-bottom: medium none; border-left: medium none; border-right: medium none; border-top: medium none; font-size: x-small; margin: 2px; padding-bottom: 2px; padding-left: 2px; padding-right: 2px; padding-top: 2px; text-align: left; }
	td.header { background-color: transparent; font-weight: bold; color: #4e4887; width: 3.3em; padding-left: 0px; margin-bottom: 0.5em; }
	td.inline { background-color: transparent; }
	td.param { font-weight: bold; font-style: italic; padding-right: 20px; }
	td.transition { padding-right: 10px; }
	th { background-color: #336699; color: #ddeeff; border-bottom: medium none; border-left: medium none; border-right: medium none; border-top: medium none; font-size: x-small; margin: 2px; padding-bottom: 2px; padding-left: 4px; padding-right: 4px; padding-top: 2px; text-align: left; }
	ul { margin-top: 0.5em; }
	li.referrer { display: inline; padding-right: 8px; }
	li.dependency { display: inline; padding-right: 8px; }
	li.seealso { display: inline; padding-right: 8px; }
	li.attribute { display: inline; padding-right: 8px; }
	li.post { display: inline; padding-right: 8px; }
	li.author { display: inline; padding-right: 8px; }
	li.fixes { display: inline; padding-right: 8px; }
	li.see { display: inline; padding-right: 8px; }
	li.changelog { display: inline; }
	.symbol { padding-right: 8px; }
	ol { margin-top: 0.5em; }
	span.paraminfo { font-weight:bold; color: #336699; }
	h1 { color: #4e4887; font-size: x-large; margin-bottom: 0.5em; margin-top: 1em; padding-left: 4px; }
	h2 { border-right: #4e4887 8px solid; border-top: #4e4887 2px solid; color: #4e4887; margin-bottom: 0.5em; margin-top: 1em; }
	h2.general { border: none; }
	h3 { color: #4e4887; font-size: x-small; margin-bottom: 0.5em; }
	h4 { color: #4e4887; font-size: x-small; font-style: italic; margin-bottom: 0.5em; display: inline; margin: 50px 8px 0px 0px; }
	h5 { color: #4e4887; font-size: xx-small; margin-bottom: 0.5em; }
	h6 { color: #4e4887; font-size: xx-small; font-style: italic; margin-bottom: 0.5em; }
	div.library { text-align: center; border-right: #4e4887 8px solid; border-top: #4e4887 2px solid; color: #4e4887; margin-bottom: 0.5em; margin-top: 1em; }
	h1.library { text-align: center; color: #4e4887; margin-top: 0.3em; }
	h2.library { text-align: center; border: none; }
	pre { background-color: #ddeeff; font-size: small; margin: 1em; }
	div.member-header { display: none; }
	div.members > .member-header:nth-child(1) { display: block; }
</style>
</head>
<body>
	<!-- <h1><xsl:value-of select="doc/assembly/name" /></h1> -->
	<xsl:apply-templates select="/doc/general" />

	<div class="members">
		<xsl:apply-templates select="/doc/members/member" mode="rest">
			<xsl:with-param name="type" select="'T:'" />
			<xsl:with-param name="title" select="'Enums'" />
		</xsl:apply-templates>

		<xsl:apply-templates select="/doc/members/member" mode="rest">
			<xsl:with-param name="type" select="'C:'" />
			<xsl:with-param name="title" select="'Constants'" />
		</xsl:apply-templates>

		<xsl:apply-templates select="/doc/members/member" mode="rest">
			<xsl:with-param name="type" select="'F:'" />
			<xsl:with-param name="title" select="'Variables'" />
		</xsl:apply-templates>

		<xsl:apply-templates select="/doc/members/member" mode="rest">
			<xsl:with-param name="type" select="'M:'" />
			<xsl:with-param name="title" select="'Functions'" />
		</xsl:apply-templates>
	</div>
</body>
</html>
</xsl:template>

<xsl:template match="general">
    <xsl:apply-templates />
    <br />
</xsl:template>

<xsl:template match="member[library]" mode="library">
	<xsl:param name="library" />
	<xsl:param name="type" />
	<xsl:param name="title" select="''" />
	<xsl:if test="library = $library and substring(@name,1,2) = $type">
		<xsl:apply-templates select="." mode="full">
			<xsl:with-param name="title" select="$title" />
		</xsl:apply-templates>
	</xsl:if>
</xsl:template>

<xsl:template match="member[not(library)]" mode="library">
</xsl:template>

<!-- Clean up the rest of the members that have no "library" specifier -->
<xsl:template match="member[library]" mode="rest">
</xsl:template>

<xsl:template match="member[not(library)]" mode="rest">
	<xsl:param name="type" />
	<xsl:param name="title" select="''" />
	<xsl:if test="substring(@name,1,2) = $type">
		<xsl:apply-templates select="." mode="full">
			<xsl:with-param name="title" select="$title" />
		</xsl:apply-templates>
	</xsl:if>
</xsl:template>

<xsl:template match="member" mode="full">
	<xsl:param name="title" />
	<xsl:choose>
		<xsl:when test="substring(@name,1,2) = 'T:'">
			<div class="member-header"><br /><h1>## <xsl:value-of select="$title" /></h1><br /></div>
			<div class="member-content">
				<br />
				<a><xsl:attribute name="name"><xsl:value-of select="substring(@name,3)" /></xsl:attribute><h2>### <code>`<xsl:value-of select="substring(@name,3)" />`</code>:</h2></a>
				<br />
				<xsl:apply-templates select="summary" />
				<xsl:if test="remarks">
					<br /><h3>#### Remarks</h3><br />
					<xsl:apply-templates select="remarks" />
				</xsl:if>
				<xsl:if test="member">
					<br /><h3>#### Members</h3><br />
					<blockquote>
					<xsl:apply-templates select="member" mode="submember" />
					</blockquote>
				</xsl:if>
				<xsl:apply-templates select="example" />
				<xsl:if test="referrer">
					<br /><h3>#### Used by</h3><br />
					<br /><xsl:apply-templates select="referrer" /><br />
				</xsl:if>
				<xsl:if test="fixes">
					<br /><h3>#### Fixes</h3><br />
					<br /><xsl:apply-templates select="fixes" /><br />
				</xsl:if>
				<xsl:if test="dependency">
					<br /><h3>#### Depends on</h3><br />
					<br /><xsl:apply-templates select="dependency" /><br />
				</xsl:if>
				<xsl:if test="seealso">
					<br /><h3>#### See Also</h3><br />
					<br /><xsl:apply-templates select="seealso" /><br />
				</xsl:if>
			</div>
		</xsl:when>
		<xsl:when test="substring(@name,1,2) = 'C:'">
			<div class="member-header"><br /><h1>## <xsl:value-of select="$title" /></h1><br /></div>
			<div class="member-content">
				<br />
				<a><xsl:attribute name="name"><xsl:value-of select="substring(@name,3)" /></xsl:attribute><h2>### <code>`<xsl:value-of select="substring(@name,3)" />`</code>:</h2></a>
				<br /><br />
				| **Value** | <code>`<xsl:value-of select="@value" />:`</code> |<br />
				<xsl:apply-templates select="summary" />
				<xsl:apply-templates select="tagname" />
				<xsl:apply-templates select="size" />
				<xsl:if test="remarks">
					<br /><h3>#### Remarks</h3><br />
					<xsl:apply-templates select="remarks" />
				</xsl:if>
				<xsl:apply-templates select="example" />
				<xsl:if test="referrer">
					<br /><h3>#### Used by</h3><br />
					<br /><xsl:apply-templates select="referrer" /><br />
				</xsl:if>
				<xsl:if test="fixes">
					<br /><h3>#### Fixes</h3><br />
					<br /><xsl:apply-templates select="fixes" /><br />
				</xsl:if>
				<xsl:if test="dependency">
					<br /><h3>#### Depends on</h3><br />
					<br /><xsl:apply-templates select="dependency" /><br />
				</xsl:if>
				<xsl:if test="seealso">
					<br /><h3>#### See Also</h3><br />
					<br /><xsl:apply-templates select="seealso" /><br />
				</xsl:if>
			</div>
		</xsl:when>
		<xsl:when test="substring(@name,1,2) = 'M:'">
			<div class="member-header"><br /><h1>## <xsl:value-of select="$title" /></h1><br /></div>
			<div class="member-content">
				<br />
				<a><xsl:attribute name="name"><xsl:value-of select="substring(@name,3)" /></xsl:attribute><h2>### <code>`<xsl:value-of select="substring(@name,3)" />`</code>:</h2></a>
				<br />
				<xsl:apply-templates select="summary" />
				<br /><h3>#### Syntax</h3><br /><br /><pre>```pawn<br /><xsl:value-of select="@syntax" /><br />```</pre><br />
				<xsl:if test="param">
					<br /><xsl:apply-templates select="param" /><br />
				</xsl:if>
				<xsl:apply-templates select="tagname" />
				<xsl:apply-templates select="returns" />
				<xsl:if test="remarks">
					<br /><h3>#### Remarks</h3><br />
					<xsl:apply-templates select="remarks" />
				</xsl:if>
				<xsl:apply-templates select="example" />
				<xsl:if test="referrer">
					<br /><h3>#### Used by</h3><br />
					<br /><xsl:apply-templates select="referrer" /><br />
				</xsl:if>
				<xsl:if test="fixes">
					<br /><h3>#### Fixes</h3><br />
					<br /><xsl:apply-templates select="fixes" /><br />
				</xsl:if>
				<xsl:if test="dependency">
					<br /><h3>#### Depends on</h3><br />
					<br /><xsl:apply-templates select="dependency" /><br />
				</xsl:if>
				<xsl:if test="attribute">
					<br /><h3>#### Attributes</h3><br />
					<br /><xsl:apply-templates select="attribute" /><br />
				</xsl:if>
				<xsl:apply-templates select="automaton" />
				<xsl:if test="transition">
					<br /><h3>#### Transition table</h3><br />
					<br />
						<table class="transition">
							<tr><th>Source</th><th>Target</th><th>Condition</th></tr>
							<xsl:apply-templates select="transition" />
						</table>
					<br />
				</xsl:if>
				<xsl:apply-templates select="stacksize" />
				<xsl:if test="seealso">
					<br /><h3>#### See Also</h3><br />
					<br /><xsl:apply-templates select="seealso" /><br />
				</xsl:if>
			</div>
		</xsl:when>
		<xsl:when test="substring(@name,1,6) = 'F:FIX_'">
			<!-- This does nothing, just hides fixes from variables -->
		</xsl:when>
		<xsl:when test="substring(@name,1,2) = 'F:'">
			<div class="member-header"><br /><h1>## <xsl:value-of select="$title" /></h1><br /></div>
			<div class="member-content">
				<br />
				<a><xsl:attribute name="name"><xsl:value-of select="substring(@name,3)" /></xsl:attribute><h2>### <code>`<xsl:value-of select="substring(@name,3)" />`</code>:</h2></a>
				<br />
				<xsl:apply-templates select="summary" />
				<xsl:apply-templates select="tagname" />
				<xsl:if test="remarks">
					<br /><h3>#### Remarks</h3><br />
					<xsl:apply-templates select="remarks" />
				</xsl:if>
				<xsl:apply-templates select="example" />
				<xsl:if test="referrer">
					<br /><h3>#### Used by</h3><br />
					<br /><xsl:apply-templates select="referrer" /><br />
				</xsl:if>
				<xsl:if test="fixes">
					<br /><h3>#### Fixes</h3><br />
					<br /><xsl:apply-templates select="fixes" /><br />
				</xsl:if>
				<xsl:if test="dependency">
					<br /><h3>#### Depends on</h3><br />
					<br /><xsl:apply-templates select="dependency" /><br />
				</xsl:if>
				<xsl:if test="seealso">
					<br /><h3>#### See Also</h3><br />
					<br /><xsl:apply-templates select="seealso" /><br />
				</xsl:if>
			</div>
		</xsl:when>
	</xsl:choose>
</xsl:template>

<!-- Show the list of fixes first -->
<xsl:template match="member" mode="fixes">
	<xsl:choose>
		<xsl:when test="substring(@name,1,6) = 'F:FIX_'">
			<br />
			<a><xsl:attribute name="name"><xsl:value-of select="substring(@name,3)" /></xsl:attribute><h2>### <xsl:value-of select="substring(@name,7)" />:</h2></a>
			<br />
			<xsl:apply-templates select="fix" />
		</xsl:when>
	</xsl:choose>
</xsl:template>

<xsl:template match="member" mode="submember">
	<xsl:choose>
		<xsl:when test="substring(@name,1,2) = 'C:'">
			* <code>`<xsl:value-of select="substring(@name,3)" /> = <xsl:value-of select="@value" />`</code><br />
		</xsl:when>
	</xsl:choose>
</xsl:template>

<xsl:template match="summary">
	<br /><xsl:apply-templates /><br />
</xsl:template>

<xsl:template match="param">
	| <code>`<xsl:value-of select="@name" />`</code> | <xsl:apply-templates /> |<br />
</xsl:template>

<xsl:template match="paraminfo">
	<code>`<xsl:apply-templates />`</code>
</xsl:template>

<xsl:template match="tagname">
	| **Tag** | <code>`<xsl:value-of select="@value" />:`</code> |<br />
</xsl:template>

<xsl:template match="size">
	| **Size** | <code>`<xsl:value-of select="@value" />:`</code> |<br />
</xsl:template>

<xsl:template match="returns">
	<br /><h3>#### Returns</h3><br />
	<br /><xsl:apply-templates /><br />
</xsl:template>

<xsl:template match="remarks">
	<br /><xsl:apply-templates /><br />
</xsl:template>

<xsl:template match="example">
	<br /><h3>#### Example</h3><br />
	<br /><xsl:apply-templates /><br />
</xsl:template>

<xsl:template match="attribute">
	* <code>`<xsl:value-of select="@name" />`</code><br />
</xsl:template>

<xsl:template match="referrer">
	* <a><xsl:attribute name="href">#<xsl:value-of select="@name" /></xsl:attribute><span class="link-text">[<code>`<xsl:value-of select="@name" />`</code>]</span><span class="link-href">(#<xsl:value-of select="@name" />)</span></a><br />
</xsl:template>

<xsl:template match="dependency">
	* <a><xsl:attribute name="href">#<xsl:value-of select="@name" /></xsl:attribute><span class="link-text">[<code>`<xsl:value-of select="@name" />`</code>]</span><span class="link-href">(#<xsl:value-of select="@name" />)</span></a><br />
</xsl:template>

<xsl:template match="stacksize">
	<br /><h3>#### Estimated stack usage </h3><br />
	<p><xsl:value-of select="@value" /> cells</p>
</xsl:template>

<xsl:template match="automaton">
	<br /><h3>#### Automaton</h3><br />
	<p><xsl:value-of select="@name" /></p>
</xsl:template>

<xsl:template match="transition">
	<tr>
		<td class="transition"><xsl:value-of select="@source" /></td>
		<td class="transition"><xsl:value-of select="@target" /></td>
		<td><xsl:value-of select="@condition" /></td>
	</tr>
</xsl:template>

<xsl:template match="code">
	<br /><pre>```pawn<br /><xsl:apply-templates /><br />```</pre><br />
</xsl:template>

<xsl:template match="seealso">
	* <a><xsl:attribute name="href">#<xsl:value-of select="@name" /></xsl:attribute><span class="link-text">[<code>`<xsl:value-of select="@name" />`</code>]</span><span class="link-href">(#<xsl:value-of select="@name" />)</span></a><br />
</xsl:template>

<xsl:template match="paramref">
	<i><xsl:value-of select="@name" /></i>
</xsl:template>

<xsl:template match="c"><code>`<xsl:apply-templates />`</code></xsl:template>

<xsl:template match="em"><em>*<xsl:apply-templates />*</em></xsl:template>

<xsl:template match="ul"><br /><ul><xsl:apply-templates /></ul><br /></xsl:template>

<xsl:template match="ol"><br /><ol><xsl:apply-templates /></ol><br /></xsl:template>

<xsl:template match="li"><li>* <xsl:apply-templates /><br /></li></xsl:template>

<xsl:template match="p"><hr class="para" /><br /><xsl:apply-templates /><br /></xsl:template>

<xsl:template match="para"><hr class="para" /><br /><xsl:apply-templates /><br /></xsl:template>

<xsl:template match="section"><br /><h1 class="general">## <xsl:apply-templates /></h1><br /></xsl:template>

<xsl:template match="subsection"><br /><h2 class="general">### <xsl:apply-templates /></h2><br /></xsl:template>

<xsl:template match="library">
	<br /><br />__________________________________________<hr /><br /><br />

	<h1 class="library"><xsl:value-of select="@name" /></h1>
	<h1 class="library">==========================================</h1><br />
	<xsl:if test="@description">
		<br /><h2 class="library"><xsl:value-of select="@description" /></h2>
		<h2 class="library">------------------------------------------</h2><br />
	</xsl:if>
	<br /><xsl:apply-templates /><br />
	<div class="members">
		<xsl:if test="@name = 'fixes.inc'">
			<br /><h1>## Fixes</h1><br />
			<xsl:apply-templates select="/doc/members/member" mode="fixes" />
		</xsl:if>

		<xsl:apply-templates select="/doc/members/member" mode="library">
			<xsl:with-param name="library" select="@name" />
			<xsl:with-param name="type" select="'T:'" />
			<xsl:with-param name="title" select="'Enums'" />
		</xsl:apply-templates>

		<xsl:apply-templates select="/doc/members/member" mode="library">
			<xsl:with-param name="library" select="@name" />
			<xsl:with-param name="type" select="'C:'" />
			<xsl:with-param name="title" select="'Constants'" />
		</xsl:apply-templates>

		<xsl:apply-templates select="/doc/members/member" mode="library">
			<xsl:with-param name="library" select="@name" />
			<xsl:with-param name="type" select="'F:'" />
			<xsl:with-param name="title" select="'Variables'" />
		</xsl:apply-templates>

		<xsl:apply-templates select="/doc/members/member" mode="library">
			<xsl:with-param name="library" select="@name" />
			<xsl:with-param name="type" select="'M:'" />
			<xsl:with-param name="title" select="'Functions'" />
		</xsl:apply-templates>
	</div>

	<br /><br />__________________________________________<hr /><br /><br />
</xsl:template>

<xsl:template match="br"><br /></xsl:template>
<xsl:template match="indent">&#160;&#160;&#160;&#160;</xsl:template>

<xsl:template match="a">
	<xsl:choose>
		<xsl:when test="node()"><a><xsl:attribute name="href"><xsl:value-of select="@href" /></xsl:attribute><span class="link-text">[<xsl:apply-templates />]</span><span class="link-href">(<xsl:value-of select="@href" />)</span></a></xsl:when>
		<xsl:otherwise><a><xsl:attribute name="href"><xsl:value-of select="@href" /></xsl:attribute><span class="link-text">[<xsl:value-of select="@href" />]</span><span class="link-href">(<xsl:value-of select="@href" />)</span></a></xsl:otherwise>
	</xsl:choose>
</xsl:template>

<xsl:template match="symbolref">
	<a><xsl:attribute name="href">#<xsl:value-of select="@name" /></xsl:attribute><span class="link-text">[<code>`<xsl:value-of select="@name" />`</code>]</span><span class="link-href">(#<xsl:value-of select="@name" />)</span></a>
</xsl:template>

<xsl:template match="symbol">
	* <a><xsl:attribute name="href">#<xsl:value-of select="@name" /></xsl:attribute><span class="link-text">[<code>`<xsl:value-of select="@name" />`</code>]</span><span class="link-href">(#<xsl:value-of select="@name" />)</span></a>:&#160;<xsl:apply-templates /><br />
</xsl:template>

<xsl:template match="synonym">
	* <code>`<xsl:value-of select="@name" />`</code>: Synonym for <code>`<xsl:value-of select="@for" />`</code><xsl:apply-templates />.<br />
</xsl:template>

<xsl:template match="changelog">
	<br /><h3>#### <xsl:value-of select="@date" /></h3><br />
	<xsl:apply-templates />
</xsl:template>


<!-- fixes.inc -->

<xsl:template match="fix">
	<xsl:if test="@fixed">
		<br />**Fixed in <xsl:value-of select="@fixed" />**<br />
	</xsl:if>
	<xsl:if test="@disabled">
		<xsl:if test="@disabled='true'">
			<br />**Disabled By Default**<br />
		</xsl:if>
	</xsl:if>

	<br /><h3>#### Problem</h3><br />
	<xsl:apply-templates select="problem" />
	<br /><h3>#### Solution</h3><br />
	<xsl:apply-templates select="solution" />
	<xsl:if test="see">
		<br /><h3>#### See</h3><br />
		<br /><xsl:apply-templates select="see" /><br />
	</xsl:if>
	<xsl:if test="author">
		<br /><h3>#### Author</h3>(s)<br />
		<br /><xsl:apply-templates select="author" /><br />
	</xsl:if>
	<xsl:if test="post">
		<br /><h3>#### Post</h3>(s)<br />
		<br /><xsl:apply-templates select="post" /><br />
	</xsl:if>
</xsl:template>

<xsl:template match="post">
	* <a><xsl:attribute name="href"><xsl:value-of select="@href" /></xsl:attribute><span class="link-text">[<xsl:value-of select="@href" />]</span><span class="link-href">(<xsl:value-of select="@href" />)</span></a><br />
</xsl:template>
<xsl:template match="see">
	* <a><xsl:attribute name="href">#<xsl:apply-templates /></xsl:attribute><span class="link-text">[<code>`<xsl:apply-templates />`</code>]</span><span class="link-href">(#<xsl:apply-templates />)</span></a><br />
</xsl:template>
<xsl:template match="author">
	*   <xsl:choose>
			<xsl:when test="@href">
				<a><xsl:attribute name="href"><xsl:value-of select="@href" /></xsl:attribute><span class="link-text">[<xsl:apply-templates />]</span><span class="link-href">(<xsl:value-of select="@href" />)</span></a>
			</xsl:when>
			<xsl:otherwise>
				<xsl:apply-templates />
			</xsl:otherwise>
		</xsl:choose>
	<br />
</xsl:template>
<xsl:template match="problem">
	<br /><xsl:apply-templates /><br />
</xsl:template>
<xsl:template match="solution">
	<br /><xsl:apply-templates /><br />
</xsl:template>

<xsl:template match="fixeslist"><xsl:apply-templates /></xsl:template>

<xsl:template match="fixes">
	* <a><xsl:attribute name="href">#FIX_<xsl:apply-templates /></xsl:attribute><span class="link-text">[<xsl:apply-templates />]</span><span class="link-href">(#FIX_<xsl:apply-templates />)</span></a><br />
</xsl:template>

</xsl:stylesheet>

