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
	li.referrer { padding-right: 8px; }
	li.dependency { padding-right: 8px; }
	li.seealso { padding-right: 8px; }
	li.attribute { padding-right: 8px; }
	li.post { padding-right: 8px; }
	li.author { padding-right: 8px; }
	li.fixes { padding-right: 8px; }
	li.see { padding-right: 8px; }
	li.changelog { }
	.symbol { padding-right: 8px; }
	ol { margin-top: 0.5em; }
	span.paraminfo { font-weight: bold; color: #336699; }
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
	.license { text-align: center; border: none; }
	pre { background-color: #ddeeff; font-size: small; margin: 1em; }
	div.member-header { display: none; }
	div.members > .member-header:nth-child(1) { display: block; }
	.render-mode .render { display: auto; }
	.render-mode .markdown { display: none; }
	.render-mode .markdown { display: none; }
	.render-mode .markdown { display: none; }
	.markdown-mode .markdown { display: auto; }
	.markdown-mode .render { display: none; }
	.library-divider hr { border-radius: 5px; border: 5px solid #4e4887; }
	.switcher { position: fixed; top: 0; right: 0; padding: 20px; background-color: #ddeeff; font-size: large; }
	.switcher-hidden { display: none; }
</style>
</head>
<body class="markdown-mode">
	<h1 class="library"><xsl:value-of select="/doc/assembly/name" /></h1>
	<h1 class="library markdown">==========================================</h1>

	<div class="members">
		<xsl:apply-templates select="/doc/members/member" mode="rest">
			<xsl:with-param name="type" select="'T:'" />
			<xsl:with-param name="title" select="'Enums'" />
		</xsl:apply-templates>
	</div>

	<div class="members">
		<xsl:apply-templates select="/doc/members/member" mode="rest">
			<xsl:with-param name="type" select="'C:'" />
			<xsl:with-param name="title" select="'Constants'" />
		</xsl:apply-templates>
	</div>

	<div class="members">
		<xsl:apply-templates select="/doc/members/member" mode="rest">
			<xsl:with-param name="type" select="'F:'" />
			<xsl:with-param name="title" select="'Variables'" />
		</xsl:apply-templates>
	</div>

	<div class="members">
		<xsl:apply-templates select="/doc/members/member" mode="rest">
			<xsl:with-param name="type" select="'M:'" />
			<xsl:with-param name="title" select="'Functions'" />
		</xsl:apply-templates>
	</div>

	<xsl:apply-templates select="/doc/general" />

	<div class="switcher-hidden" id="switcher-container">
		<label for="markdown-switcher">
			<input type="checkbox" id="markdown-switcher" onchange="showMarkdown()" />
			Show Markdown
		</label>
	</div>

	<script type="text/javascript">
		var container = document.getElementById("switcher-container");
		var switcher = document.getElementById("markdown-switcher");

		if (container != null)
		{
			// Show the dialog only if JS is available.
			container.className = "switcher";

			// And change the default.
			document.body.className = "render-mode";
		}

		function showMarkdown()
		{
			if (switcher == null)
			{
			}
			else if (switcher.checked)
			{
				document.body.className = "markdown-mode";
			}
			else
			{
				document.body.className = "render-mode";
			}
		}
	</script>
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
			<div class="member-header"><br /><h1><span class="markdown">##&#160;</span><xsl:value-of select="$title" /></h1><br /></div>
			<div class="member-content">
				<br />
				<a><xsl:attribute name="name"><xsl:value-of select="substring(@name,3)" /></xsl:attribute><h2><span class="markdown">###&#160;</span><code><span class="markdown">`</span><xsl:value-of select="substring(@name,3)" /><span class="markdown">`</span></code>:</h2></a>
				<br />
				<xsl:apply-templates select="summary" />
				<xsl:if test="remarks">
					<h3><span class="markdown">####&#160;</span>Remarks</h3><br />
					<xsl:apply-templates select="remarks" />
				</xsl:if>
				<xsl:if test="member">
					<h3><span class="markdown">####&#160;</span>Members</h3><br />
					<blockquote>
					<ul><xsl:apply-templates select="member" mode="submember" /></ul>
					</blockquote>
				</xsl:if>
				<xsl:apply-templates select="example" />
				<xsl:if test="referrer">
					<h3><span class="markdown">####&#160;</span>Used by</h3><br />
					<ul><xsl:apply-templates select="referrer" /></ul>
				</xsl:if>
				<xsl:if test="fixes">
					<h3><span class="markdown">####&#160;</span>Fixes</h3>
					<ul><xsl:apply-templates select="fixes" /></ul>
				</xsl:if>
				<xsl:if test="dependency">
					<h3><span class="markdown">####&#160;</span>Depends on</h3>
					<ul><xsl:apply-templates select="dependency" /></ul>
				</xsl:if>
				<xsl:if test="seealso">
					<h3><span class="markdown">####&#160;</span>See Also</h3>
					<ul><xsl:apply-templates select="seealso" /></ul>
				</xsl:if>
			</div>
		</xsl:when>
		<xsl:when test="substring(@name,1,2) = 'C:'">
			<div class="member-header"><br /><h1><span class="markdown">##&#160;</span><xsl:value-of select="$title" /></h1><br /></div>
			<div class="member-content">
				<br />
				<a><xsl:attribute name="name"><xsl:value-of select="substring(@name,3)" /></xsl:attribute><h2><span class="markdown">###&#160;</span><code><span class="markdown">`</span><xsl:value-of select="substring(@name,3)" /><span class="markdown">`</span></code>:</h2></a>
				<br /><br />
				<xsl:apply-templates select="summary" />
				<p class="noindent">
					<table>
						<tr>
							<td class="inline markdown">|&#160;</td><td class="header inline"><b><span class="markdown">**</span>Value<span class="markdown">**</span></b></td><td class="inline markdown">&#160;|&#160;</td><td class="inline"><code><span class="markdown">`</span><xsl:value-of select="@value" /><span class="markdown">`</span></code></td><td class="inline markdown">&#160;|</td>
						</tr>
						<xsl:apply-templates select="tagname" />
						<xsl:apply-templates select="size" />
					</table>
				</p>
				<xsl:if test="remarks">
					<h3><span class="markdown">####&#160;</span>Remarks</h3><br />
					<xsl:apply-templates select="remarks" />
				</xsl:if>
				<xsl:apply-templates select="example" />
				<xsl:if test="referrer">
					<h3><span class="markdown">####&#160;</span>Used by</h3><br />
					<ul><xsl:apply-templates select="referrer" /></ul>
				</xsl:if>
				<xsl:if test="fixes">
					<h3><span class="markdown">####&#160;</span>Fixes</h3>
					<ul><xsl:apply-templates select="fixes" /></ul>
				</xsl:if>
				<xsl:if test="dependency">
					<h3><span class="markdown">####&#160;</span>Depends on</h3>
					<ul><xsl:apply-templates select="dependency" /></ul>
				</xsl:if>
				<xsl:if test="seealso">
					<h3><span class="markdown">####&#160;</span>See Also</h3>
					<ul><xsl:apply-templates select="seealso" /></ul>
				</xsl:if>
			</div>
		</xsl:when>
		<xsl:when test="substring(@name,1,2) = 'M:'">
			<div class="member-header"><br /><h1><span class="markdown">##&#160;</span><xsl:value-of select="$title" /></h1><br /></div>
			<div class="member-content">
				<br />
				<a><xsl:attribute name="name"><xsl:value-of select="substring(@name,3)" /></xsl:attribute><h2><span class="markdown">###&#160;</span><code><span class="markdown">`</span><xsl:value-of select="substring(@name,3)" /><span class="markdown">`</span></code>:</h2></a>
				<br />
				<xsl:apply-templates select="summary" />
				<br /><h3><span class="markdown">####&#160;</span>Syntax</h3><br /><br /><pre><span class="markdown">```pawn<br /></span><xsl:value-of select="@syntax" /><span class="markdown"><br />```</span></pre><br />
				<xsl:if test="param">
					<p><table class="param"><xsl:apply-templates select="param" /></table></p>
				</xsl:if>
				<p class="noindent">
					<table>
						<xsl:apply-templates select="tagname" />
					</table>
				</p>
				<xsl:apply-templates select="returns" />
				<xsl:if test="remarks">
					<h3><span class="markdown">####&#160;</span>Remarks</h3>
					<xsl:apply-templates select="remarks" />
				</xsl:if>
				<xsl:apply-templates select="example" />
				<xsl:if test="referrer">
					<h3><span class="markdown">####&#160;</span>Used by</h3>
					<ul><xsl:apply-templates select="referrer" /></ul>
				</xsl:if>
				<xsl:if test="fixes">
					<h3><span class="markdown">####&#160;</span>Fixes</h3>
					<ul><xsl:apply-templates select="fixes" /></ul>
				</xsl:if>
				<xsl:if test="dependency">
					<h3><span class="markdown">####&#160;</span>Depends on</h3>
					<ul><xsl:apply-templates select="dependency" /></ul>
				</xsl:if>
				<xsl:if test="attribute">
					<h3><span class="markdown">####&#160;</span>Attributes</h3>
					<ul><xsl:apply-templates select="attribute" /></ul>
				</xsl:if>
				<xsl:apply-templates select="automaton" />
				<xsl:if test="transition">
					<h3><span class="markdown">####&#160;</span>Transition table</h3>
					<p>
						<table class="transition">
							<tr><th>Source</th><th>Target</th><th>Condition</th></tr>
							<xsl:apply-templates select="transition" />
						</table>
					</p><br />
				</xsl:if>
				<xsl:apply-templates select="stacksize" />
				<xsl:if test="seealso">
					<h3><span class="markdown">####&#160;</span>See Also</h3><br />
					<ul><xsl:apply-templates select="seealso" /></ul>
				</xsl:if>
			</div>
		</xsl:when>
		<xsl:when test="substring(@name,1,6) = 'F:FIX_'">
			<!-- This does nothing, just hides fixes from variables -->
		</xsl:when>
		<xsl:when test="substring(@name,1,2) = 'F:'">
			<div class="member-header"><br /><h1><span class="markdown">##&#160;</span><xsl:value-of select="$title" /></h1><br /></div>
			<div class="member-content">
				<br />
				<a><xsl:attribute name="name"><xsl:value-of select="substring(@name,3)" /></xsl:attribute><h2><span class="markdown">###&#160;</span><code><span class="markdown">`</span><xsl:value-of select="substring(@name,3)" /><span class="markdown">`</span></code>:</h2></a>
				<br />
				<xsl:apply-templates select="summary" />
				<p class="noindent">
					<table>
						<xsl:apply-templates select="tagname" />
					</table>
				</p>
				<xsl:if test="remarks">
					<h3><span class="markdown">####&#160;</span>Remarks</h3><br />
					<xsl:apply-templates select="remarks" />
				</xsl:if>
				<xsl:apply-templates select="example" />
				<xsl:if test="referrer">
					<h3><span class="markdown">####&#160;</span>Used by</h3><br />
					<ul><xsl:apply-templates select="referrer" /></ul>
				</xsl:if>
				<xsl:if test="fixes">
					<h3><span class="markdown">####&#160;</span>Fixes</h3>
					<ul><xsl:apply-templates select="fixes" /></ul>
				</xsl:if>
				<xsl:if test="dependency">
					<h3><span class="markdown">####&#160;</span>Depends on</h3>
					<ul><xsl:apply-templates select="dependency" /></ul>
				</xsl:if>
				<xsl:if test="seealso">
					<h3><span class="markdown">####&#160;</span>See Also</h3>
					<ul><xsl:apply-templates select="seealso" /></ul>
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
			<a><xsl:attribute name="name"><xsl:value-of select="substring(@name,3)" /></xsl:attribute><h2><span class="markdown">###&#160;</span><xsl:value-of select="substring(@name,7)" />:</h2></a>
			<br />
			<xsl:apply-templates select="fix" />
		</xsl:when>
	</xsl:choose>
</xsl:template>

<xsl:template match="member" mode="submember">
	<xsl:choose>
		<xsl:when test="substring(@name,1,2) = 'C:'">
			<li><span class="markdown">*&#160;</span><code><span class="markdown">`</span><xsl:value-of select="substring(@name,3)" /> = <xsl:value-of select="@value" /><span class="markdown">`</span></code></li>
		</xsl:when>
	</xsl:choose>
</xsl:template>

<xsl:template match="summary">
	<p><xsl:apply-templates /></p><br />
</xsl:template>

<xsl:template match="param">
	<tr>
		<td class="inline markdown">|&#160;</td><td class="param"><code><span class="markdown">`</span><xsl:value-of select="@name" /><span class="markdown">`</span></code></td><td class="inline markdown">&#160;|&#160;</td><td><xsl:apply-templates /></td><td class="inline markdown">&#160;|</td>
	</tr>
</xsl:template>

<xsl:template match="paraminfo">
	<span class="paraminfo"><code><span class="markdown">`</span><xsl:apply-templates /><span class="markdown">`</span></code></span>
</xsl:template>

<xsl:template match="tagname">
	<tr>
		<td class="inline markdown">|&#160;</td><td class="header inline"><b><span class="markdown">**</span>Tag<span class="markdown">**</span></b></td><td class="inline markdown">&#160;|&#160;</td><td class="inline"><code><span class="markdown">`</span><xsl:value-of select="@value" />:<span class="markdown">`</span></code></td><td class="inline markdown">&#160;|</td>
	</tr>
</xsl:template>

<xsl:template match="size">
	<tr>
		<td class="inline markdown">|&#160;</td><td class="header inline"><b><span class="markdown">**</span>Size<span class="markdown">**</span></b></td><td class="inline markdown">&#160;|&#160;</td><td class="inline"><code><span class="markdown">`</span><xsl:value-of select="@value" /><span class="markdown">`</span></code></td><td class="inline markdown">&#160;|</td>
	</tr>
</xsl:template>

<xsl:template match="returns">
	<h3><span class="markdown">####&#160;</span>Returns</h3>
	<p><xsl:apply-templates /></p><br />
</xsl:template>

<xsl:template match="remarks">
	<p><xsl:apply-templates /></p><br />
</xsl:template>

<xsl:template match="example">
	<h3><span class="markdown">####&#160;</span>Example</h3>
	<p><xsl:apply-templates /></p><br />
</xsl:template>

<xsl:template match="attribute">
	<li class="attribute"><span class="markdown">*&#160;</span><code><span class="markdown">`</span><xsl:value-of select="@name" /><span class="markdown">`</span></code></li>
</xsl:template>

<xsl:template match="referrer">
	<li class="referrer"><span class="markdown">*&#160;</span><a><xsl:attribute name="href">#<xsl:value-of select="@name" /></xsl:attribute><span class="markdown">[</span><code><span class="markdown">`</span><xsl:value-of select="@name" /><span class="markdown">`</span></code><span class="markdown">](#<xsl:value-of select="@name" />)</span></a></li>
</xsl:template>

<xsl:template match="dependency">
	<li class="dependency"><span class="markdown">*&#160;</span><a><xsl:attribute name="href">#<xsl:value-of select="@name" /></xsl:attribute><span class="markdown">[</span><code><span class="markdown">`</span><xsl:value-of select="@name" /><span class="markdown">`</span></code><span class="markdown">](#<xsl:value-of select="@name" />)</span></a></li>
</xsl:template>

<xsl:template match="stacksize">
	<h3><span class="markdown">####&#160;</span>Estimated stack usage</h3>
	<p><xsl:value-of select="@value" /> cells</p><br />
</xsl:template>

<xsl:template match="automaton">
	<h3><span class="markdown">####&#160;</span>Automaton</h3>
	<p><xsl:value-of select="@name" /></p><br />
</xsl:template>

<xsl:template match="transition">
	<tr>
		<td class="transition"><xsl:value-of select="@source" /></td>
		<td class="transition"><xsl:value-of select="@target" /></td>
		<td><xsl:value-of select="@condition" /></td>
	</tr>
</xsl:template>

<xsl:template match="code">
	<br /><pre><span class="markdown">```pawn<br /></span><xsl:apply-templates /><span class="markdown"><br />```</span></pre><br />
</xsl:template>

<xsl:template match="seealso">
	<span class="markdown">*&#160;</span><a><xsl:attribute name="href">#<xsl:value-of select="@name" /></xsl:attribute><span class="markdown">[</span><code><span class="markdown">`</span><xsl:value-of select="@name" /><span class="markdown">`</span></code><span class="markdown">](#<xsl:value-of select="@name" />)</span></a><br />
</xsl:template>

<xsl:template match="paramref">
	<i><xsl:value-of select="@name" /></i>
</xsl:template>

<xsl:template match="c"><code><span class="markdown">`</span><xsl:apply-templates /><span class="markdown">`</span></code></xsl:template>

<xsl:template match="em"><em><span class="markdown">*</span><xsl:apply-templates /><span class="markdown">*</span></em></xsl:template>

<xsl:template match="ul"><br /><ul><xsl:apply-templates /></ul><br /></xsl:template>

<xsl:template match="ol"><br /><ol><xsl:apply-templates /></ol><br /></xsl:template>

<xsl:template match="li"><li><span class="markdown">*&#160;</span><xsl:apply-templates /><br /></li></xsl:template>

<xsl:template match="p"><hr class="para" /><br /><xsl:apply-templates /><br /></xsl:template>

<xsl:template match="para"><hr class="para" /><br /><xsl:apply-templates /><br /></xsl:template>

<xsl:template match="section"><h1 class="general"><span class="markdown">##&#160;</span><xsl:apply-templates /></h1></xsl:template>

<xsl:template match="subsection"><h2 class="general"><span class="markdown">###&#160;</span><xsl:apply-templates /></h2></xsl:template>

<xsl:template match="library">
	<div class="library-divider"><br /><br /><span class="markdown">__________________________________________</span><hr /><br /><br /></div>

	<h1 class="library"><xsl:value-of select="@name" /></h1>
	<h1 class="library markdown">==========================================</h1>
	<xsl:if test="@description">
		<h2 class="library"><xsl:value-of select="@description" /></h2>
		<h2 class="library markdown">------------------------------------------</h2>
	</xsl:if>
	<br /><xsl:apply-templates /><br />
	<xsl:if test="@name = 'fixes.inc'">
		<div class="members">
			<br /><h1><span class="markdown">##&#160;</span>Fixes</h1><br />
			<xsl:apply-templates select="/doc/members/member" mode="fixes" />
		</div>
	</xsl:if>

	<div class="members">
		<xsl:apply-templates select="/doc/members/member" mode="library">
			<xsl:with-param name="library" select="@name" />
			<xsl:with-param name="type" select="'T:'" />
			<xsl:with-param name="title" select="'Enums'" />
		</xsl:apply-templates>
	</div>

	<div class="members">
		<xsl:apply-templates select="/doc/members/member" mode="library">
			<xsl:with-param name="library" select="@name" />
			<xsl:with-param name="type" select="'C:'" />
			<xsl:with-param name="title" select="'Constants'" />
		</xsl:apply-templates>
	</div>

	<div class="members">
		<xsl:apply-templates select="/doc/members/member" mode="library">
			<xsl:with-param name="library" select="@name" />
			<xsl:with-param name="type" select="'F:'" />
			<xsl:with-param name="title" select="'Variables'" />
		</xsl:apply-templates>
	</div>

	<div class="members">
		<xsl:apply-templates select="/doc/members/member" mode="library">
			<xsl:with-param name="library" select="@name" />
			<xsl:with-param name="type" select="'M:'" />
			<xsl:with-param name="title" select="'Functions'" />
		</xsl:apply-templates>
	</div>
</xsl:template>

<xsl:template match="license"><div class="license"><xsl:apply-templates /></div></xsl:template>

<xsl:template match="br"><br /></xsl:template>
<xsl:template match="indent">&#160;&#160;&#160;&#160;</xsl:template>

<xsl:template match="a">
	<xsl:choose>
		<xsl:when test="node()"><a><xsl:attribute name="href"><xsl:value-of select="@href" /></xsl:attribute><span class="markdown">[</span><xsl:apply-templates /><span class="markdown">](<xsl:value-of select="@href" />)</span></a></xsl:when>
		<xsl:otherwise><a><xsl:attribute name="href"><xsl:value-of select="@href" /></xsl:attribute><span class="markdown">[</span><xsl:value-of select="@href" /><span class="markdown">](<xsl:value-of select="@href" />)</span></a></xsl:otherwise>
	</xsl:choose>
</xsl:template>

<xsl:template match="symbolref">
	<a><xsl:attribute name="href">#<xsl:value-of select="@name" /></xsl:attribute><span class="markdown">[</span><code><span class="markdown">`</span><xsl:value-of select="@name" /><span class="markdown">`</span></code><span class="markdown">](#<xsl:value-of select="@name" />)</span></a>
</xsl:template>

<xsl:template match="symbol">
	<li><span class="markdown">*&#160;</span><a><xsl:attribute name="href">#<xsl:value-of select="@name" /></xsl:attribute><span class="markdown">[</span><code><span class="markdown">`</span><xsl:value-of select="@name" /><span class="markdown">`</span></code><span class="markdown">](#<xsl:value-of select="@name" />)</span></a>:&#160;<xsl:apply-templates /></li>
</xsl:template>

<xsl:template match="synonym">
	<li><span class="markdown">*&#160;</span><code><span class="markdown">`</span><xsl:value-of select="@name" /><span class="markdown">`</span></code>: Synonym for <code><span class="markdown">`</span><xsl:value-of select="@for" /><span class="markdown">`</span></code><xsl:apply-templates />.</li>
</xsl:template>

<xsl:template match="changelog">
	<li class="changelog"><h3 class="general">#### <xsl:value-of select="@date" /></h3>
	<ul><xsl:apply-templates /></ul></li>
</xsl:template>

<!-- fixes.inc -->

<xsl:template match="fix">
	<xsl:if test="@fixed">
		<br /><b><span class="markdown">**</span>Fixed in <xsl:value-of select="@fixed" /><span class="markdown">**</span></b><br />
	</xsl:if>
	<xsl:if test="@disabled">
		<xsl:if test="@disabled='true'">
			<br /><b><span class="markdown">**</span>Disabled By Default<span class="markdown">**</span></b><br />
		</xsl:if>
	</xsl:if>

	<br /><h3><span class="markdown">####&#160;</span>Problem</h3><br />
	<xsl:apply-templates select="problem" />
	<br /><h3><span class="markdown">####&#160;</span>Solution</h3><br />
	<xsl:apply-templates select="solution" />
	<xsl:if test="see">
		<br /><h3><span class="markdown">####&#160;</span>See</h3><br />
		<br /><xsl:apply-templates select="see" /><br />
	</xsl:if>
	<xsl:if test="author">
		<br /><h3><span class="markdown">####&#160;</span>Author(s)</h3><br />
		<br /><xsl:apply-templates select="author" /><br />
	</xsl:if>
	<xsl:if test="post">
		<br /><h3><span class="markdown">####&#160;</span>Post(s)</h3><br />
		<br /><xsl:apply-templates select="post" /><br />
	</xsl:if>
</xsl:template>

<xsl:template match="post">
	<li class="post"><span class="markdown">*&#160;</span><a><xsl:attribute name="href"><xsl:value-of select="@href" /></xsl:attribute><span class="markdown">[</span><xsl:value-of select="@href" /><span class="markdown">](<xsl:value-of select="@href" />)</span></a></li>
</xsl:template>
<xsl:template match="see">
	<li class="see"><span class="markdown">*&#160;</span><a><xsl:attribute name="href">#<xsl:apply-templates /></xsl:attribute><span class="markdown">[</span><code><span class="markdown">`</span><xsl:apply-templates /><span class="markdown">`</span></code><span class="markdown">](#<xsl:apply-templates />)</span></a></li>
</xsl:template>
<xsl:template match="author">
	<li class="author"><span class="markdown">*&#160;</span>
	<xsl:choose>
			<xsl:when test="@href">
				<a><xsl:attribute name="href"><xsl:value-of select="@href" /></xsl:attribute><span class="markdown">[</span><xsl:apply-templates /><span class="markdown">](<xsl:value-of select="@href" />)</span></a>
			</xsl:when>
			<xsl:otherwise>
				<xsl:apply-templates />
			</xsl:otherwise>
		</xsl:choose>
	</li>
</xsl:template>
<xsl:template match="problem">
	<p><xsl:apply-templates /></p><br />
</xsl:template>
<xsl:template match="solution">
	<p><xsl:apply-templates /></p><br />
</xsl:template>

<xsl:template match="fixeslist"><xsl:apply-templates /></xsl:template>

<xsl:template match="fixes">
	<li class="fixes"><span class="markdown">*&#160;</span><a><xsl:attribute name="href">#FIX_<xsl:apply-templates /></xsl:attribute><span class="markdown">[</span><xsl:apply-templates /><span class="markdown">](#FIX_<xsl:apply-templates />)</span></a></li>
</xsl:template>

</xsl:stylesheet>

